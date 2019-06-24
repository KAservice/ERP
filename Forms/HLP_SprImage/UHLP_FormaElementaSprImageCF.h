#ifndef UHLP_FormaElementaSprImageCFH                  
#define UHLP_FormaElementaSprImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaElementaSprImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaElementaSprImageCF();                                                           
   ~THLP_FormaElementaSprImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
