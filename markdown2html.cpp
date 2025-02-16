#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

void convertMarkdownToHtml(string & inputFile, string &outputfile) {

    ifstream hin("input.md");
    if (!hin) {
        cout << "Error: File not found\n";
        return ;
    }

    string markdown = "";
    string line;
    while (getline(hin, line)) {
        markdown += line + "\n";
    }
    hin.close();

    if (markdown.empty()) {
        cout << "No data in  Input file\n";

    }
    stringstream ss(markdown);
    string html = "";
    bool inList = false; // Flag to track list items

    while (getline(ss, line)) {
        // Convert headings
        regex pattern("^#\\s*(.+)$");
        if (regex_search(line, pattern)) {
            line = regex_replace(line, pattern, "<h1>$1</h1>");
        }

        // Convert **bold** text
        regex pattern2("\\*\\*(.+?)\\*\\*");
        line = regex_replace(line, pattern2, "<b>$1</b>");

        // Convert *italic* text
        regex pattern3("\\*(.+?)\\*");
        line = regex_replace(line, pattern3, "<i>$1</i>");

        // Convert links [text](url)
        regex pattern4("\\[(.+?)\\]\\((.+?)\\)");
        line = regex_replace(line, pattern4, "<a href=\"$2\">$1</a>");

        // Convert list items (- Item 1)
        regex listPattern("^\\s*-\\s*(.+)$");
        if (regex_search(line, listPattern)) {
            if (!inList) {
                html += "<ul>\n"; // Start list if not already inside one
                inList = true;
            }
            line = regex_replace(line, listPattern, "<li>$1</li>");
        } else if (inList) {
            html += "</ul>\n"; // Close list when a non-list line is found
            inList = false;
        }

        html += line + "\n";
    }

    if (inList) {
        html += "</ul>\n"; // Ensure list is closed if input ends with list
    }

 // Write HTML output to the specified file
 ofstream outFile(outputfile);
 if (!outFile) {
     cout << "Error: Could not create output file - " << outputfile << endl;
     return;
 }

 outFile << "<html>\n<body>\n" << html << "\n</body>\n</html>";
 outFile.close();

 cout << "Conversion successful! Output written to: " << outputfile << endl;
}




