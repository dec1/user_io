# user_io
Example Qt app. User data input and persistence. 

## Structure
This is a Workspace containing 3 (sub) projects
- **main**. The main (user facing) application 
- **test**. Example unit and workflow tests
- **common**. A (static) library containing all the code which is common to and needed by the others


## Requirements
Qt. Tested with version 5.9 (windows/linux), and 5.7 (macOS)
https://www.qt.io

- Download and install Qt. 
- Open the *workspace.pro* file with Qt Creator.
- Build/run the *main* project. 
- (Optionally) Build/run the *test* project with some example tests.

## Functionality
The user is presented with a modal dialog where they can enter several values, and (optionally) save them to a file *werte.txt* in their home directory. Context sensitive help provides some guidance.

## Design/Architecture
The projects makes use of some best practices in software engineering and in particular Qt (eg appropriate use of design patterns). 

### Internationalization 
The app loads the appropriate translation files at startup - currently German or English (default). Any number of additional languages can be added simply by providing the translations (http://doc.qt.io/qt-5/qtlinguist-index.html). Similarly other locale dependent settings (decimal separators etc) are handled transparently by the app.

### Extensibility/Maintainability
- The number and type of values the user can enter can easily be changed (in a single function)
- The data is currently exported to a file, but the separation of data marshalling and persistence makes passing the data instead to eg a web service trivial. The orthogonal implementation thereof also ensures that passing/saving the data in different format (eg xml instead of or in addition to the current json) is easily realizable. The standardized format of the file (json) ensures that third party software have minimum difficulty reading/parsing it.
- Currently the data entered by the user is sorted in ascending order before its saved. To use a different sorting method simply pass a different algorithm as a parameter to the sort function (Strategy pattern)
- A version number is also saved to the file in a preamble (header section) to allow the possibility of changing the format in a future version of the software without breaking backward compatibility
