#include "qureg.hpp"

double run_circuit(unsigned int qbit)
{
    int num_qubits = 2;
    iqs::QubitRegister<ComplexDP> psi (num_qubits, "base", 0);

    psi.Print("Initial state =");

    psi.ApplyHadamard(0);
    psi.ApplyCPauliX(0, 1);

    psi.Print("Measurement =");

    psi.Normalize();

    return psi.GetProbability(qbit);
}