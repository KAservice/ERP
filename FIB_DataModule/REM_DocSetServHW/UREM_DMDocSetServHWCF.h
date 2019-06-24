#ifndef UREM_DMDocSetServHWCFH                  
#define UREM_DMDocSetServHWCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocSetServHWCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocSetServHWCF();                                                           
   ~TREM_DMDocSetServHWCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
