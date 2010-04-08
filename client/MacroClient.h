#ifndef MacroClientServer_h
#define MacroClientServer_h

#define DODO 16666//1000000
#define PORT_TCP 44444;
#define PORT_UDP_ENVOI 44445;//Inversé chez le serveur, évidemment
#define PORT_UDP_ECOUTE 44444;
#define CHARSTART '0'
#define CHARSTOP '1'
#define CHARQUIT '9'

/** PLATEAU DE JEU **/
#define CASE_VIDE '1'
#define CASE_AVECMURINCASSABLE '2'
#define CASE_AVECMURCASSABLE '3'
#define CASE_AVECMALUS '4'
#define CASE_AVECBONUS_FLAMME '5'
#define CASE_AVECBONUS_ROLLER '6'
#define CASE_AVECBONUS_BOMBE '7'
#define CASE_AVECBOMBE '8'
#define CASE_ENFLAMMEE '9'


#endif //MacroClientServer_h
