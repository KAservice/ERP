#ifndef UHLP_FormaElementaSprImageGrpCFH                  
#define UHLP_FormaElementaSprImageGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaElementaSprImageGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaElementaSprImageGrpCF();                                                           
   ~THLP_FormaElementaSprImageGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
