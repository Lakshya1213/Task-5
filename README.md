# Task-5
CLI-MARKDOWNCONVERTER
There are 7 files in makrdown convertrer project.
1) cli.cpp(This is a main file which call fuction which conversiion took place)
2) html2markdown.cpp(converts html to markdwown)
3) input.html(this contain input in html for html2markdown)
4) output.md(shows the ouput of html2markdown)
5) markdown2html(converts markdown to html)
6) input.md(this contain input in md for markdown2html)
7) output.md(shows the output of markdown2html)

HOW TO USE THIS TOOL->
1. **Compile the program** using g++:
   ```sh
   g++ cli.cpp -o converter

2. Run the tool:
 ./convertor --help
output=>  Usage
The tool follows this syntax:
./convertor <option> <inputfile> <outputfile> 
Options:
--md2html → Convert Markdown to HTML
--html2md → Convert HTML to Markdown
3. Examples
#Convert Markdown to HTML:
./convertor --md2html input.md output.html
#Convert HTML to Markdown:
./convertor --html2md input.html output.md
#Show Help:
./convertor --help
5.Error Handling
#If you enter invalid arguments:
./convertor --md2html input.md
Output:
 showHelp();
#If you enter an invalid option:
./convertor --wrong input.md output.html
Output:
showHelp();
5. If input file doest not have..
   ->Then output:
   No data in input file.
   
