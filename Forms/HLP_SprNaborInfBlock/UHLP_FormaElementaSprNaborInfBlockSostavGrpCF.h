#ifndef UHLP_FormaElementaSprNaborInfBlockSostavGrpCFH                  
#define UHLP_FormaElementaSprNaborInfBlockSostavGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaElementaSprNaborInfBlockSostavGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaElementaSprNaborInfBlockSostavGrpCF();                                                           
   ~THLP_FormaElementaSprNaborInfBlockSostavGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
