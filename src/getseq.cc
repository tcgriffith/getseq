// #include "structure.h"
// #include <boost/filesystem.hpp>

#include "PDB.h"

using namespace std;
// using namespace misc;

vector<string> pdblist;

void read_params(int argc, char const *argv[]){
    if (argc < 2){
        std::cout << "       Get Protein or RNA Sequences from PDB, in Fasta Format" << endl;
        std::cout << "Usage: " << argv[0] <<" pdb1[ pdb2 pdb3 ...]" << endl;
        exit(0);
    }

    pdblist.clear();
    for (int i0 = 1; i0 < argc ; i0++){
        pdblist.push_back(argv[i0]);
    }
}

void run_getseq(int argc, char const *argv[]){

    read_params(argc, argv);
    for (string apdb : pdblist){
        structure * astr = new structure(apdb);
        for (auto & achain: astr->chains){

            // boost::filesystem::path p(apdb);

            string name = misc::basename(apdb);

            string fasta_info = "> " + name + " "+achain.get_chainid() + " " +to_string(achain.get_residue_num());

            cout << fasta_info << endl;
            cout << achain.get_seq() << endl;
        }
    }




}

int main(int argc, char const *argv[])
{
    run_getseq(argc,argv);
    /* code */
    return 0;
}
