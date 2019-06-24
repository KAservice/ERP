#ifndef UREM_FormaCustQueryDvCFH                  
#define UREM_FormaCustQueryDvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaCustQueryDvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaCustQueryDvCF();                                                           
   ~TREM_FormaCustQueryDvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
