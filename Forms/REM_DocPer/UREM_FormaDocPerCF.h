#ifndef UREM_FormaDocPerCFH                  
#define UREM_FormaDocPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocPerCF();                                                           
   ~TREM_FormaDocPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
