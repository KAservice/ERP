#ifndef UREM_DMDocAktCFH                  
#define UREM_DMDocAktCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocAktCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocAktCF();                                                           
   ~TREM_DMDocAktCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
