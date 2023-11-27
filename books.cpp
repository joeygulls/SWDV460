#include <iostream>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>

using namespace xercesc;

int main() {
    try {
        // Initialize the Xerces-C++ library
        XMLPlatformUtils::Initialize();

        // Create a DOM parser
        XercesDOMParser parser;
        
        // Specify XML file to parse
        const char* xmlFile = "example.xml";
        
        // Parse the XML file
        parser.parse(xmlFile);

        // Get the DOM document
        DOMDocument* doc = parser.getDocument();

        // Display the XML content
        if (doc) {
            // Get the root element
            DOMElement* root = doc->getDocumentElement();
            
            // Display the content recursively
            displayElement(root);
        }
    } catch (const XMLException& e) {
        std::cerr << "Error during initialization: " << XMLString::transcode(e.getMessage()) << std::endl;
        return 1;
    } catch (const DOMException& e) {
        std::cerr << "DOM Exception: " << XMLString::transcode(e.getMessage()) << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception occurred" << std::endl;
        return 1;
    }

    // Terminate Xerces
    XMLPlatformUtils::Terminate();

    return 0;
}

void displayElement(DOMElement* element, int depth = 0) {
    if (!element) {
        return;
    }

    // Get the tag name and value of the current element
    std::string tagName = XMLString::transcode(element->getTagName());
    std::string value = XMLString::transcode(element->getTextContent());

    // Display the element with proper indentation
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }

    std::cout << "<" << tagName << ">" << value << "</" << tagName << ">" << std::endl;

    // Recursively display child elements
    DOMNodeList* children = element->getChildNodes();
    const XMLSize_t childCount = children->getLength();

    for (XMLSize_t i = 0; i < childCount; ++i) {
        DOMNode* child = children->item(i);
        if (child->getNodeType() == DOMNode::ELEMENT_NODE) {
            displayElement(static_cast<DOMElement*>(child), depth + 1);
        }
    }
}
