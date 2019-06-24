#ifndef UREM_DMDocRealCFH                  
#define UREM_DMDocRealCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_DMDocRealCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_DMDocRealCF();                                                           
   ~TREM_DMDocRealCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
