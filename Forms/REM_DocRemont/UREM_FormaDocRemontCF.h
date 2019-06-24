#ifndef UREM_FormaDocRemontCFH                  
#define UREM_FormaDocRemontCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocRemontCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocRemontCF();                                                           
   ~TREM_FormaDocRemontCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
