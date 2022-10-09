#include "../intel-qs/include/qureg.hpp"

int main(int argc, char **argv)
{
    iqs::mpi::Environment env(argc, argv);
    if (env.IsUsefulRank() == false) return 0;
    
    int num_qubits = 2;
    iqs::QubitRegister<ComplexDP> psi (num_qubits, "base", 0);

    psi.Print("Initial state =");

    psi.ApplyHadamard(0);
    psi.ApplyCPauliX(0, 1);

    psi.Print("Measurement =");
    return 0;
}