#ifndef UDMRegZakCFH                  
#define UDMRegZakCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMRegZakCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMRegZakCF();                                                           
   ~TDMRegZakCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
