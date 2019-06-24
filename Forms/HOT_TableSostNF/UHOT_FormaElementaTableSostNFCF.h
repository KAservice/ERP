#ifndef UHOT_FormaElementaTableSostNFCFH                  
#define UHOT_FormaElementaTableSostNFCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaElementaTableSostNFCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaElementaTableSostNFCF();                                                           
   ~THOT_FormaElementaTableSostNFCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
