#ifndef UREM_FormaGurProverokCFH                  
#define UREM_FormaGurProverokCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaGurProverokCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaGurProverokCF();                                                           
   ~TREM_FormaGurProverokCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
