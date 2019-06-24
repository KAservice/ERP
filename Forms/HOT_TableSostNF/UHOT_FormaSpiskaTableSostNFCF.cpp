#include "vcl.h"
#pragma hdrstop  
#include "UHOT_FormaSpiskaTableSostNFCF.h"   
#include "UHOT_FormaSpiskaTableSostNFImpl.h"  
#include "IHOT_FormaSpiskaTableSostNF.h"  
#pragma package(smart_init)  
extern int NumObject;  
//---------------------------------------------------------------
THOT_FormaSpiskaTableSostNFCF::THOT_FormaSpiskaTableSostNFCF()   
{    
NumRefs=0; 
++NumObject; 
} 
//---------------------------------------------------------------
THOT_FormaSpiskaTableSostNFCF::~THOT_FormaSpiskaTableSostNFCF() 
{ 
--NumObject;  
} 
//---------------------------------------------------------------
int THOT_FormaSpiskaTableSostNFCF::kanQueryInterface(REFIID id_interface, void**ppv)  
{    
int result=0;  
if (id_interface==IID_IkanUnknown) 
	{  
	*ppv=static_cast<IkanUnknown*> (this);  
	result=-1;  
	} 
else if (id_interface==IID_IkanClassFactory) 
	{  
	*ppv=static_cast<IkanClassFactory*> (this); 
	result=-1; 
	} 
else  
	{   
	*ppv=NULL;  
	result=0;  
	return result;  
	} 
kanAddRef();
return result;  
}   
//---------------------------------------------------------------
int THOT_FormaSpiskaTableSostNFCF::kanAddRef(void) 
{     
return (++NumRefs);    
}    
//---------------------------------------------------------------
int THOT_FormaSpiskaTableSostNFCF::kanRelease(void)  
{  
if (--NumRefs==0)   
	{  
	delete this;   
	}    
return NumRefs;  
}  
//---------------------------------------------------------------
int THOT_FormaSpiskaTableSostNFCF::kanCreateInstance(REFIID id_interface, void ** ppv)  
{  
int result=0;  
		THOT_FormaSpiskaTableSostNFImpl * ob=new THOT_FormaSpiskaTableSostNFImpl();  
		if (ob->kanQueryInterface(id_interface, ppv)==-1)   
			{       
			result=-1;  
			}    
		else     
			{           
			delete ob;   
			result=0;   
			}      
return result;  
}       
//---------------------------------------------------------------
