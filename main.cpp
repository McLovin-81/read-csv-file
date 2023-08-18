#include <iostream>
#include <string>
#include <fstream> // Use to read csv files.
#include <sstream>
#include <vector>

struct Record
{
    std::string date;
    int open;
    int high;
    int low;
    int end;
    std::string currency;
    int volume;
};

int main()
{
    // Open the CSV file for reading
    std::ifstream file("history.csv"); // File path
    
    if(!file.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<Record> recordsVec;

    // Read each line from te CSV file
    while(std::getline(file, line))
    {
        // Create an input string stream to process the line
        std::stringstream iss(line);
        Record recordObj;

        // Extract data from the line using the specified delimiter ';'
        std::getline(iss, recordObj.date, ';'); // Read and store the date
        iss >> recordObj.open;                  // Read and store the open value 
        iss.ignore();                       // Ignore the semicolon
        iss >> recordObj.high;                  // Read and sotre the high value
        iss.ignore();                        // Ignore the semicolon
        iss >> recordObj.low;                   // Read and store low value
        iss.ignore();                        // Ignore the semicolon^
        iss >> recordObj.end;                   // Read and sotre the end value
        iss.ignore();                        // Ignore the semicolon;
        std::getline(iss, recordObj.currency, ';'); // Read and store the currency
        iss >> recordObj.volume;                // Read and store the end volume

        // Add the extracted record to the vector for records 
        recordsVec.push_back(recordObj);
    }
    // Now the data are stored in the 'records' vector

    // Print out the extracted data for each record
    int recordsSize = recordsVec.size();
    for(int i = 1; i < recordsSize; i++)
    {
        std::cout << "Date: " << recordsVec[i].date
                    << " Open: " << recordsVec[i].open
                    << " High: " << recordsVec[i].high
                    << " Low: " << recordsVec[i].low
                    << " End: " << recordsVec[i].end
                    << " Curency: " << recordsVec[i].currency
                    << " volume: " << recordsVec[i].volume;
    }

    return 0;
}
