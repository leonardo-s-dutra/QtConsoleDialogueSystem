#include "ConsoleDialogue.h"

int main(int argc, char *argv[])
{
    ConsoleDialogue dialogue(nullptr);

    if (argc < 2)
    {
        out << "No dialogue file parsed.\n" << flush;
        return -1;
    }

    else if (argc > 2)
    {
        out << "Too many arguments parsed.\n" << flush;
        return -1;
    }

    LOAD_STATUS status = dialogue.loadDialogue(argv[1]);
            
    switch (status)
    {
    case NOT_XML_EXTENSION:
        out << "Dialogue must be a .xml file.\n\n" << flush;
        break;

    case INVALID_FILE:
        out << "Dialogue must be a .xml file.\n\n" << flush;
        break;

    case INVALID_CONTENT:
        out << "Could not set content to dialogue.\n\n" << flush;
        break;

    case NO_NODE_ID:
        out << "Node with missing ID found.\n\n" << flush;
        break;

    case NO_NODE_TEXT:
        out << "Node with missing text found.\n\n" << flush;
        break;

    case NO_OPTION_TEXT:
        out << "Option with missing text found.\n\n" << flush;
        break;

    case NO_OPTION_DESTINATION_ID:
        out << "Option with missing destination ID found.\n\n" << flush;
        break;

    default:
        dialogue.run();
    }

    out << "\t---END OF DIALOGUE---\n\n" << flush;
    out << "Press ENTER to exit..." << flush;
    in.read(1);

    return 0;
}
