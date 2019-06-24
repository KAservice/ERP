#ifndef UREM_FormaSpiskaSprDefectModelNeisprCFH                  
#define UREM_FormaSpiskaSprDefectModelNeisprCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaSpiskaSprDefectModelNeisprCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaSpiskaSprDefectModelNeisprCF();                                                           
   ~TREM_FormaSpiskaSprDefectModelNeisprCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
