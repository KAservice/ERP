#ifndef UHOT_FormaSpiskaTableSostNFCFH                  
#define UHOT_FormaSpiskaTableSostNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaSpiskaTableSostNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaSpiskaTableSostNFCF();                                                           
   ~THOT_FormaSpiskaTableSostNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
