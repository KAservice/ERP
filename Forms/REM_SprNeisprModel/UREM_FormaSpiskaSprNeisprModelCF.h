#ifndef UREM_FormaSpiskaSprNeisprModelCFH                  
#define UREM_FormaSpiskaSprNeisprModelCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprNeisprModelCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprNeisprModelCF();                                                           
   ~TREM_FormaSpiskaSprNeisprModelCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
