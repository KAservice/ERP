#ifndef UHOT_DMDocOtmenaBronCFH                  
#define UHOT_DMDocOtmenaBronCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMDocOtmenaBronCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMDocOtmenaBronCF();                                                           
   ~THOT_DMDocOtmenaBronCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
