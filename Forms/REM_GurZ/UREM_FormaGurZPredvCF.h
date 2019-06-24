#ifndef UREM_FormaGurZPredvCFH                  
#define UREM_FormaGurZPredvCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurZPredvCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurZPredvCF();                                                           
   ~TREM_FormaGurZPredvCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
