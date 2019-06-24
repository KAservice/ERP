#ifndef UHLP_FormaElementaSprInfBlockGrpCFH                  
#define UHLP_FormaElementaSprInfBlockGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaElementaSprInfBlockGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaElementaSprInfBlockGrpCF();                                                           
   ~THLP_FormaElementaSprInfBlockGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
