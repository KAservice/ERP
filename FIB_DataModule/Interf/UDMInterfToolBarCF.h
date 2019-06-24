#ifndef UDMInterfToolBarCFH                  
#define UDMInterfToolBarCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMInterfToolBarCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMInterfToolBarCF();                                                           
   ~TDMInterfToolBarCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
