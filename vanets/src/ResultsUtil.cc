//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "ResultsUtil.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;


double ResultsUtil::totalAvg(string fileName, string resultType){


    string word;
    string value;
    stringstream lineStream;
    double currentResult = 0;

    const char *fileNameConstChar = fileName.c_str();
    ifstream configFile (fileNameConstChar);
    if(configFile.is_open()){

        for(string line; getline(configFile, line);){
            lineStream<<line;
            while(lineStream >> word){
		cout<<"Word: " << word << endl; 
                if (word == resultType){
                    lineStream >> value;
                    currentResult = atof(value.c_str());
                }
            }
        }
    }

    return currentResult;
}

ResultsUtil::~ResultsUtil() {

}

