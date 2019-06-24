#ifndef UREM_FormaCustQueryCFH                  
#define UREM_FormaCustQueryCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaCustQueryCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaCustQueryCF();                                                           
   ~TREM_FormaCustQueryCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
