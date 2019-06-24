#ifndef UREM_FormaGurZDopCFH                  
#define UREM_FormaGurZDopCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurZDopCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurZDopCF();                                                           
   ~TREM_FormaGurZDopCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
