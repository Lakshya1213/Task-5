#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

void convertHtmlToMarkdown(string &inputFile, string &outputFile) {
    ifstream hin(inputFile);
    if (!hin) {
        cout << "Error: File not found\n";
        return;
    }
    // takes input form hin file
    string html = "";
    string line;
    while (getline(hin, line)) {
        html += line + "\n";
    }
    hin.close();

    if (html.empty()) {
        cout << "No data in Input file\n";
        return;
    }

    stringstream ss(html);
    string markdown = "";

    while (getline(ss, line)) {
        // Convert headings
        regex pattern("<h1>(.+?)</h1>");
        line = regex_replace(line, pattern, "# $1");

        // Convert <b>bold</b> text
        regex pattern2("<b>(.+?)</b>");
        line = regex_replace(line, pattern2, "**$1**");

        // Convert <i>italic</i> text
        regex pattern3("<i>(.+?)</i>");
        line = regex_replace(line, pattern3, "*$1*");

        // Convert links <a href="URL">text</a>
        html = regex_replace(html, regex("<a href=\"(.*?)\">(.*?)</a>"), "[$2]($1)");

        // Convert list items <li>Item</li>
        regex listPattern("<li>(.+?)</li>");
        line = regex_replace(line, listPattern, "- $1");

        markdown += line + "\n";
    }

    // Write Markdown output to the specified file
    ofstream outFile(outputFile);
    if (!outFile) {
        cout << "Error: Could not create output file - " << outputFile << endl;
        return;
    }

    outFile << markdown;
    outFile.close();

    cout << "Conversion successful! Output written to: " << outputFile << endl;
}
