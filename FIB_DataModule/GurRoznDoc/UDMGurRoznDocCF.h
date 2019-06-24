#ifndef UDMGurRoznDocCFH                  
#define UDMGurRoznDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMGurRoznDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMGurRoznDocCF();                                                           
   ~TDMGurRoznDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
