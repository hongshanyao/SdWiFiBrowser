#include "printer.h"
#include <Arduino.h>
#include <Preferences.h>
#include <string.h>
#include "serial.h"  // For DEBUG_LOG

// Create a Preferences instance for storing printer settings
static Preferences prefs;

// Global printer instance
Printer printer;

bool Printer::beginPreferences(bool readonly) {
    if (!prefs.begin("printer", readonly)) {
        DEBUG_LOG("Failed to begin preferences (readonly=%d)\n", readonly);
        return false;
    }
    return true;
}

bool Printer::save(const PRINTER_INFO& info) {
    DEBUG_LOG("Saving printer name: %s\n", info.name);
    
    // Copy the new info to our internal structure
    memcpy(&printer_info, &info, sizeof(PRINTER_INFO));
    
    // Open preferences
    if (!beginPreferences(false)) {
        return false;
    }
    
    // Save to preferences
    size_t written = prefs.putString("name", printer_info.name);
    DEBUG_LOG("Bytes written to preferences: %d\n", written);
    
    // Close preferences
    prefs.end();
    
    return written > 0;
}

PRINTER_INFO Printer::read() {
    // Open preferences
    if (beginPreferences(true)) {  // true = read-only mode
        if (prefs.isKey("name")) {
            prefs.getString("name", printer_info.name, sizeof(printer_info.name));
            DEBUG_LOG("Read printer name: %s\n", printer_info.name);
        }
        prefs.end();
    }
    
    // Return the current printer info
    return printer_info;
}