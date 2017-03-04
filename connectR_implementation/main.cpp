// Copyright 2017 Timothy Oltjenbruns

#include <iostream>
#include <XmlNode.hpp>
#include <XmlUtils.hpp>
#include <fstream>
#include <XmlBuilder.hpp>

int main(int argCount, char* args[]) {
  std::cout << "Hello XmlParser World!" << std::endl;
  srand((unsigned int) time(0));
  std::ifstream file;
  file.open("behaviorTree.xml");
  if (!file.is_open()) {
    std::cout << "Behavior tree cannot be opened" << std::endl;
    return 1;
  }
  XmlBuilder builder;
  builder.build(file);
  file.close();
  if (!builder.valid()) {
    std::cout << "Behavior tree is not valid" << std::endl;
    return 2;
  }
  XmlNode behaviorTree(builder.get());
  std::cout << "Loaded behavior tree" << std::endl;
  std::cout << behaviorTree << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  while (true) {
    std::cout << "Event ('quit' to exit) : ";
    char cLine[4096];
    std::cin.getline(cLine, 4096);
    std::string line(cLine);
    if (line.compare("quit") == 0)
      return 0;
    const XmlNode* behavior(XmlUtils::searchValueBf(&behaviorTree, line));
    std::cout << "Response = ";
    if (behavior == nullptr) {
      std::cout << std::endl;
      continue;
    }
    const XmlNode* response(XmlUtils::stochasticResponse(behavior));
    auto attributeIter(std::find_if(response->getConstAttributes().begin(), response->getConstAttributes().end(),
                               [](const XmlAttribute& attribute){
                                 return attribute.getKey().compare("response") == 0;
                               }));
    if (attributeIter == response->getConstAttributes().end()) {
      std::cout << "(leaf node without response)" << std::endl;
      continue;
    }
    std::cout << attributeIter->getValue() << std::endl;
  }
}
