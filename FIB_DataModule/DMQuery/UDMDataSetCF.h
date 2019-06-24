#ifndef UDMDataSetCFH                  
#define UDMDataSetCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDataSetCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDataSetCF();                                                           
   ~TDMDataSetCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
