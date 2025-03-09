#ifndef _PRINTER_H_
#define _PRINTER_H_

/**
 * @brief Structure to hold printer information
 */
typedef struct printer_info
{
  char name[32];  // Printer name, max 31 characters + null terminator
} PRINTER_INFO;

/**
 * @brief Class to manage printer configuration
 */
class Printer {
public:
    /**
     * @brief Save printer information to non-volatile storage
     * @param info Printer information to save
     * @return true if successful, false otherwise
     */
    bool save(const PRINTER_INFO& info);
    
    /**
     * @brief Read printer information from non-volatile storage
     * @return PRINTER_INFO structure containing printer configuration
     */
    PRINTER_INFO read();
    
    /**
     * @brief Get the current printer information
     * @return Reference to the current printer information
     */
    const PRINTER_INFO& getCurrentInfo() const { return printer_info; }

private:
    PRINTER_INFO printer_info;
    
    /**
     * @brief Open preferences with the printer namespace
     * @param readonly Whether to open in readonly mode
     * @return true if successful, false otherwise
     */
    bool beginPreferences(bool readonly);
};

extern Printer printer;

#endif