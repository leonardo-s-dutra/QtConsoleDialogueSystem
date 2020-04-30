#include "ConsoleDialogue.h"


int main(int argc, char *argv[])
{
    ConsoleDialogue dialogue(nullptr);


    LOAD_STATUS status = dialogue.loadDialogue("D:/MyDialogue.xml");
    
    if (status == INVALID_FILE)
        out << "Could not open file.\n\n" << flush;

    else if (status == INVALID_CONTENT)
        out << "Could not set content.\n\n" << flush;

    else if (status == NO_NODE_ID)
        out << "Node with missing ID found.\n\n" << flush;

    else if (status == NO_NODE_TEXT)
        out << "Node with missing text found.\n\n" << flush;

    else if (status == NO_OPTION_TEXT)
        out << "Option with missing text found.\n\n" << flush;

    else if (status == NO_OPTION_DESTINATION_ID)
        out << "Option with missing destination ID found.\n\n" << flush;

    else
        dialogue.run();

    out << "\n\t---END OF DIALOGUE---\n\n" << flush;
    out << "Press ENTER to exit..." << flush;
    in.read(1);

    return 0;
}
