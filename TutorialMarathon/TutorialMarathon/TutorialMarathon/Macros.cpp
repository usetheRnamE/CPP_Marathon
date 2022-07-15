#include <iostream>

#define WAIT std::cin.get() // do not use Macros too often
#define TellTheTruth std::cout << "russo-nazi-scum sucks" << "\n";

#define OPEN_CURLY { // so mainly we just kinda "rename" anything using Macros and then we can use new "name"

//after acts that describes at 31 line we can write this nice and sick code 
#if  TUT_DEBUG == 1

#define LOG(x) std::cout << x << "\n";
#define NaziName "vaniok-ibaniok"

#elif defined(TUT_RELEASE) // in a release mode we will define macros below to nothing

#define LOG(x) 
#define NaziName

#endif //  TUT_DEBUG

//define usage with functions
#define MAIN int MAIN10() /* We use [\] to define that it is still a macros cuz macros must be written in one line*/ \
OPEN_CURLY /*strange shit but u catch the idea, are`t u? */ \
WAIT; /*non - clear if this was defined in other file or whatever(commonly bad code)*/ \
TellTheTruth /*if we write semicolun in a Macros we can write this line without it*/ \
LOG(NaziName); /*shit is getting stranger, truth however; Macros is good for logging tho, cuz we can log smth in a debug mode but in relize mode this (logging)shit will cut away*/ \
	/*To use this nice macros feature go to[project->properties->c / c++->preprocessor->prepocessor defines] and in DEBUG Configuration write smth like MyProgName_DEBUG = 1; part before "_" isn`t really matter however in a RELEASE Config write smth like MyProjName_RELEASE */ \
return 0; \
}

MAIN