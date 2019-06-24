#ifndef UDMTableNumberDocCFH                  
#define UDMTableNumberDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMTableNumberDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMTableNumberDocCF();                                                           
   ~TDMTableNumberDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
