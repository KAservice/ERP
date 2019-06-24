#ifndef UHLP_FormaSpiskaSprImageCFH                  
#define UHLP_FormaSpiskaSprImageCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THLP_FormaSpiskaSprImageCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THLP_FormaSpiskaSprImageCF();                                                           
   ~THLP_FormaSpiskaSprImageCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
