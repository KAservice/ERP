#ifndef UHOT_DMDocViezdCFH                  
#define UHOT_DMDocViezdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMDocViezdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMDocViezdCF();                                                           
   ~THOT_DMDocViezdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
