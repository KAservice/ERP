#ifndef UDMSprInfBaseCFH                  
#define UDMSprInfBaseCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprInfBaseCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprInfBaseCF();                                                           
   ~TDMSprInfBaseCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
