#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "arrayseq.hh"
#include "dlinkseq.hh"
#include "seq.hh"
using TestType = int;
inline std::string usage(const char* pn) {
    return std::string("usage: ") + pn + "[-a] " + "INTS_FILE_PATH";
}
void readints(const std::string& fileName, Seq<TestType>* spointer) {
    std::ifstream in(fileName);
    if (!in)
     {
      std::cerr << "cannot read \"" << fileName << "\"" << std::endl;
      std::exit(0);
     }
    TestType obj;
    while(in >> obj)
    {
        spointer->push(obj);
    }
}
void output(Seq<TestType> *seq) {
    auto start = seq->cbegin();
    auto end = seq->cend();
    auto& startj = *start;
    auto& endj = *end;
    --endj;
    
    while (startj && endj) {
        std::cout << *startj << std::endl;
        std::cout << *endj << std::endl;
        ++startj;
        --endj;
    }
}
int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        std::cerr << usage(argv[0]) << std::endl;
        return EINVAL;
    }
    SeqPtr<TestType> spointer;
    std::string filename;
    if (argc == 3) {
        if (std::string(argv[1]) == "-a") {
            filename = argv[2];
            spointer = ArraySeq<TestType>::make();
        }
        else if (std::string(argv[1]) == "-x") {
            std::cout << usage(argv[0]) << std::endl;
            return 0;
        }
        else {
            std::cerr << usage(argv[0]) << std::endl;
            return EINVAL;
        }
    }
    else {
        filename = argv[1];
        spointer = DLinkSeq<TestType>::make();
    
    }
    readints(filename, spointer.get());
    output(spointer.get());
}
