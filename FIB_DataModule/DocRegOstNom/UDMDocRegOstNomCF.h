#ifndef UDMDocRegOstNomCFH                  
#define UDMDocRegOstNomCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRegOstNomCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRegOstNomCF();                                                           
   ~TDMDocRegOstNomCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
