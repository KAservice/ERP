#ifndef UDMRegOstNomCFH                  
#define UDMRegOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMRegOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMRegOstNomCF();                                                           
   ~TDMRegOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
