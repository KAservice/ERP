#ifndef UHLP_FormaElementaSprNaborInfBlockGrpCFH                  
#define UHLP_FormaElementaSprNaborInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaElementaSprNaborInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaElementaSprNaborInfBlockGrpCF();                                                           
   ~THLP_FormaElementaSprNaborInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
