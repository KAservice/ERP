#ifndef UHOT_DMDocRealCFH                  
#define UHOT_DMDocRealCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMDocRealCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMDocRealCF();                                                           
   ~THOT_DMDocRealCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
