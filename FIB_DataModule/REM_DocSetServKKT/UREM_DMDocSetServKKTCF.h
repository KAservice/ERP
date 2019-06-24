#ifndef UREM_DMDocSetServKKTCFH                  
#define UREM_DMDocSetServKKTCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocSetServKKTCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocSetServKKTCF();                                                           
   ~TREM_DMDocSetServKKTCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
