#ifndef UHOT_DMTableSostNFCFH                  
#define UHOT_DMTableSostNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_DMTableSostNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_DMTableSostNFCF();                                                           
   ~THOT_DMTableSostNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
