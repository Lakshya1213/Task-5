#include<iostream>
#include "markdown2html.cpp"
#include "html2markdown.cpp"
using namespace std;

void showHelp() {
    cout << "Usage: ./converter <option> <inputfile> <outputfile>\n";
    cout << "Options:\n";
    cout << "  --md2html   Convert Markdown to HTML\n";
    cout << "  --html2md   Convert HTML to Markdown\n";
    cout << "  --help      Show this help message\n";
}

int main(int argc, char* argv[]) {
      showHelp(); // when you run code directly not in terminal show instruction 
      return 0;
     if (string(argv[1]) == "--help") { 
        showHelp();
        return 0;
    }

    if (argc != 4) {      
        cout << "Error: Invalid arguments!\n";
         showHelp();
    }

    string option = argv[1]; // reads ./converter
    string inputFile = argv[2]; // reads inputfile
    string outputFile = argv[3]; // reads outputfile
    
    if (option == "--md2html") {
        convertMarkdownToHtml(inputFile, outputFile);
    } else if (option == "--html2md") {
        convertHtmlToMarkdown(inputFile, outputFile);
    } else {
        cout << "Error: Invalid option!\n";
        return 1;
    }

    return 0;
}
