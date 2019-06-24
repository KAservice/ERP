#ifndef UDMXTableIsmCFH                  
#define UDMXTableIsmCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMXTableIsmCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMXTableIsmCF();                                                           
   ~TDMXTableIsmCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
