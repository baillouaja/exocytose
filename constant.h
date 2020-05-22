#ifndef CONSTANT_H_INCLUDED
#define CONSTANT_H_INCLUDED

/* Caracteristical Units */
const double kbT=4.114; // pN.nm - Energy
const double a=7.0; // nm  - Length
const double eta=0.38; // pN.µs/nm - Drag Coefficient
const double tau_eta=a*a*eta/kbT; //4.5µs - Time

/* Parameters of synaptotagmin */
const double e_bond_std_unit=-16.0; // kbT
const double e_bond=e_bond_std_unit; // Binding energy of synaptotagmin to membrane

//const double k_syn_std_unit=1.0; // pN/m
const double k_syn=2000; // Stiffness of synaptotagmin


const double ksyn_std_unit=1000.0; // MHz
const double ksyn=ksyn_std_unit*tau_eta;


const double y_syn_std_unit=5.0; // nm
const double y_syn=0.6; // Unloaded length of synaptotagmin *spring-like*


/* Table of parameters (Given units + Dimensionless) */

/* Energy */
const double e0_std_unit=28.0; // kbT
const double e0= e0_std_unit; // Energy bias

const double ef_std_unit=26.0; // kbT
const double ef= ef_std_unit; // Fusion Barrier height

/* Stiffness */
const double kc_std_unit=12.0; // pN/nm
const double kc= kc_std_unit*a*a/kbT; // Fully-Zipped stiffness

const double kn_std_unit=2.5; // pN/m
const double kn= kn_std_unit*a*a/kbT; // Half-Zipped stiffness

/* Length */
const double yf_std_unit=2.0; // nm
const double yf= yf_std_unit/a; // Fusion Barrier position

const double sigmaf_std_unit=0.3; // nm
const double sigmaf= sigmaf_std_unit/a; // Fusion Barrier width

const double y_transtion_std_unit=3.2; //nm
const double y_transition=y_transtion_std_unit/a; // Position where the transition has occured

/* Rate */
const double k_std_unit=1.0; // micros-1 = Mhz
const double k=k_std_unit*tau_eta; // Maximum zippering rate

#endif // CONSTANT_H_INCLUDED
