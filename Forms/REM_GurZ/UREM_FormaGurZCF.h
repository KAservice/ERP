#ifndef UREM_FormaGurZCFH                  
#define UREM_FormaGurZCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurZCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurZCF();                                                           
   ~TREM_FormaGurZCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
